//
// Created by 刘时明 on 2020/12/24.
//

export module dogApi;

namespace DogApi
{
    auto GetWelcomeHelper()
    { return "Welcome to CppCon 2019!"; }

    export auto GetWelcome()
    { return GetWelcomeHelper(); }
}