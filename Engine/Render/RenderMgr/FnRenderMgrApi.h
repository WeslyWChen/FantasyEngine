//
// Created by 30632 on 2025/3/9.
//

#ifndef FNRENDERMGRAPI_H
#define FNRENDERMGRAPI_H

#ifdef _WIN32
#ifdef FNRENDERMGR_BUILD
#define FNRENDERMGR_API __declspec(dllexport)
#else
#define FNRENDERMGR_API __declspec(dllimport)
#endif
#else
#define FNRENDERMGR_API
#endif

#endif  // FNRENDERMGRAPI_H
