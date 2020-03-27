/*
** EPITECH PROJECT, 2020
** folder_test
** File description:
** DLLoader
*/

#ifndef _DLLOADER_HPP_
#define _DLLOADER_HPP_

#include <dlfcn.h>
#include <string>
#include "DLLoaderException.hpp"

template <typename T>
class DLLoader {
    private:
        std::string _libraryPath;
        void *_handle;

    public:
        DLLoader<T>(const std::string &libraryPath) try : _libraryPath(libraryPath), _handle(NULL) {
            _handle = dlopen(_libraryPath.c_str(), RTLD_GLOBAL | RTLD_LAZY);
            if (!_handle)
                throw DLLoaderException("Can't open " + _libraryPath, "DLLoader");
        } catch (DLLoaderException &e) {
            throw e;
        }; 

        T *getInstance(const std::string &entryPoint) const {
            T *(*fptr)(void);
            T *obj = NULL;

            void *ret = dlsym(_handle, entryPoint.c_str());
            if (!ret)
                throw DLLoaderException("Can't access \"" + entryPoint + "\" on \"" + _libraryPath + "\" : " + dlerror() + "DLLoader");
            fptr = reinterpret_cast<T *(*)(void)>(ret);
            obj = dynamic_cast<T *>(fptr());
            if (!obj)
                throw DLLoaderException("Can't cast \"" + entryPoint + "\"'s return on \"" + _libraryPath + "\" : " + dlerror() + "DLLoader");
            return (obj);
        };
   
        ~DLLoader<T>() { 
            dlclose(_handle); 
        };     
};

#endif