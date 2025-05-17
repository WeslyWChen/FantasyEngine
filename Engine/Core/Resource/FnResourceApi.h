//
// Created by 30632 on 25-5-17.
//

#ifndef FNRESOURCEAPI_H
#define FNRESOURCEAPI_H

#ifdef _WIN32
#ifdef FNRESOURCE_BUILD
#define FNRESOURCE_API __declspec(dllexport)
#else
#define FNRESOURCE_API __declspec(dllimport)
#endif
#else
#define FNRESOURCE_API
#endif

#endif  // FNRESOURCEAPI_H
