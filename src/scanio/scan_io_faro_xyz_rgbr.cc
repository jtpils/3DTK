/*
 * scan_io_faro_xyz_rgbr implementation
 *
 * Copyright (C) Andreas Nuechter
 *
 * Released under the GPL version 3.
 *
 */


/**
 * @file scan_io_faro_xyz_rgbr.cc
 * @brief IO of a 3D scan in xyz file format plus a reflectance/intensity
 * @author Andreas Nuechter. Jacobs University Bremen, Germany.
 */

#include "scanio/scan_io_faro_xyz_rgbr.h"

const char* ScanIO_faro_xyz_rgbr::data_suffix = ".xyz";
IODataType ScanIO_faro_xyz_rgbr::spec[] = { DATA_DUMMY, DATA_DUMMY, DATA_XYZ, DATA_XYZ, DATA_XYZ,
          DATA_RGB, DATA_RGB, DATA_RGB, DATA_REFLECTANCE, DATA_TERMINATOR };
ScanDataTransform_xyz scanio_faro_xyz_tf;
ScanDataTransform& ScanIO_faro_xyz_rgbr::transform2uos = scanio_faro_xyz_tf;


/**
 * class factory for object construction
 *
 * @return Pointer to new object
 */
#ifdef _MSC_VER
extern "C" __declspec(dllexport) ScanIO* create()
#else
extern "C" ScanIO* create()
#endif
{
  return new ScanIO_faro_xyz_rgbr;
}


/**
 * class factory for object construction
 *
 * @return Pointer to new object
 */
#ifdef _MSC_VER
extern "C" __declspec(dllexport) void destroy(ScanIO *sio)
#else
extern "C" void destroy(ScanIO *sio)
#endif
{
  delete sio;
}

#ifdef _MSC_VER
BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, LPVOID lpReserved)
{
    return TRUE;
}
#endif

/* vim: set ts=4 sw=4 et: */
