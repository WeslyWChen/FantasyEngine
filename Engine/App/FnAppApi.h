//
// Created by 30632 on 2025/3/9.
//

#ifndef FNAPPAPI_H
#define FNAPPAPI_H

#ifdef _WIN32
#ifdef FNAPP_BUILD
#define FNAPP_API __declspec(dllexport)
#else
#define FNAPP_API __declspec(dllimport)
#endif
#else
#define FNAPP_API
#endif

#endif //FNAPPAPI_H
