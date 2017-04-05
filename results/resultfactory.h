#pragma once

#include "result.h"

class ResultFactory {
    public:
        template<typename TSuccessData, typename TFailureData>
        static Result<TSuccessData, TFailureData> CreateSuccess(TSuccessData data) {
            return Result<TSuccessData, TFailureData>(data);
        }

        template<typename TSuccessData, typename TFailureData>
        static Result<TSuccessData, TFailureData> CreateFailure(TFailureData data) {
            return Result<TSuccessData, TFailureData>(data);
        }
};
