#pragma once

#include <functional>

using namespace std;

template <class TSuccessData, class TFailureData>
class Result {
    private:
        TSuccessData successData;
        TFailureData failureData;
        bool isSuccess;

    public:
        Result(TSuccessData data) {
            successData = data;
            isSuccess = true;
        }

        Result(TFailureData data) {
            failureData = data;
            isSuccess = false;
        }

        template <typename TResultData>
            TResultData Match(function<TResultData (TSuccessData)> whenSuccessful, function<TResultData (TFailureData)> whenFailure) {
                return (isSuccess) ? whenSuccessful(successData) : whenFailure(failureData);
            }
};
