#pragma once

#include <any>
#include <functional>
#include <map>
#include <memory>
#include <typeinfo>

class Context;

class Registration {
    private:
        std::function<std::any(const Context &)> _resolver;

    public:
        Registration(std::function<std::any (const Context&)> resolver)
            : _resolver(resolver) {};

        template <typename T>
        T Resolve(const Context & ctx) const {
            return std::any_cast<T>(_resolver(ctx));
        }
};

class Context {
    private:
        std::map<size_t, std::unique_ptr<Registration>> _registrations;

        template <typename T>
        auto & GetRegistration() const {
            auto type = typeid(T).hash_code();
            auto it = _registrations.find(type);
            
            if (it == _registrations.end())
                throw std::invalid_argument(std::string("Type not registered: ") + typeid(T).name());

            return it->second;
        }

    public:
        Context(): _registrations(std::map<size_t, std::unique_ptr<Registration>>()) {};

        ~Context() {
        }

        template <typename TService, typename TImpl>
        void Register(const std::function<std::shared_ptr<TImpl> (const Context &)> & resolver) {
            static_assert(std::is_base_of<TService, TImpl>::value, "Implementation must be derived from Service");
            auto serviceResolver = [resolver] (const Context & ctx) { return static_cast<std::shared_ptr<TService>>(resolver(ctx)); };

            Register<std::shared_ptr<TService>>(serviceResolver);
        }

        template <typename TService, typename TImpl, typename ... TDeps>
        void RegisterShared() {
            std::function<std::shared_ptr<TImpl> (const Context &)> resolver = nullptr;

            if constexpr (sizeof...(TDeps) > 0)
                resolver = [] (const Context & ctx) { return std::make_shared<TImpl>((ctx.Resolve<TDeps>(), ...)); };
            else
                resolver = [] (const Context & ctx) { return std::make_shared<TImpl>(); };

            Register<TService, TImpl>(resolver);
        }

        template <typename TService, typename ... TDeps>
        void Register() {
            auto resolver = [] (const Context & ctx) { return TService((ctx.Resolve<TDeps>(), ...)); };

            Register<TService>(resolver);
        }

        template <typename TService>
        void Register(const std::function<TService (const Context &)> & serviceResolver) {
            auto registration = std::make_unique<Registration>(serviceResolver);
            auto type = typeid(TService).hash_code();
            _registrations.insert_or_assign(type, move(registration));
        }

        template <typename TService>
        TService Resolve() const {
            auto & registration = (std::unique_ptr<Registration> &)GetRegistration<TService>();
            return registration->Resolve<TService>(*this);
        }
};
