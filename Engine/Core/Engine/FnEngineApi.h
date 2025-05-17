//
// Created by 30632 on 25-5-17.
//

#ifndef FNENGINEAPI_H
#define FNENGINEAPI_H

#ifdef _WIN32
#ifdef FNENGINE_BUILD
#define FNENGINE_API __declspec(dllexport)
#else
#define FNENGINE_API __declspec(dllimport)
#endif
#else
#define FNENGINE_API
#endif


#endif //FNENGINEAPI_H
