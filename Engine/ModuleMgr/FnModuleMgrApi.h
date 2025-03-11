//
// Created by 30632 on 2025/3/11.
//

#ifndef FNMODULEMGRAPI_H
#define FNMODULEMGRAPI_H

#ifdef _WIN32
#ifdef FNMODULEMGR_BUILD
#define FNMODULEMGR_API __declspec(dllexport)
#else
#define FNMODULEMGR_API __declspec(dllimport)
#endif
#else
#define FNMODULEMGR_API
#endif

#endif  // FNMODULEMGRAPI_H
