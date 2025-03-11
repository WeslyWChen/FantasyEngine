//
// Created by 30632 on 2025/3/9.
//

#ifndef FNGLRENDERAPI_H
#define FNGLRENDERAPI_H

#ifdef _WIN32
#ifdef FNGLRENDER_BUILD
#define FNGLRENDER_API __declspec(dllexport)
#else
#define FNGLRENDER_API __declspec(dllimport)
#endif
#else
#define FNGLRENDER_API
#endif

#endif  // FNGLRENDERAPI_H
