//
// Created by 30632 on 2025/3/9.
//

#ifndef FNRENDERDEFAPI_H
#define FNRENDERDEFAPI_H

#ifdef _WIN32
#ifdef FNRENDERDEF_BUILD
#define FNRENDERDEF_API __declspec(dllexport)
#else
#define FNRENDERDEF_API __declspec(dllimport)
#endif
#else
#define FNRENDERDEF_API
#endif

#endif  // FNRENDERDEFAPI_H
