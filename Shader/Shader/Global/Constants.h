#pragma once
#ifdef M_PI
#undef M_PI
#endif
#define M_PI 3.14159265358979323846f
#define INV_PI 0.31830988618379067154f

// INV_TWOPI ...
#ifndef INFINITY
#define INFINITY FLT_MAX
#endif

const int nbRebondMax = 5;
const int nbEchantillon = 0;
const int nbEchantillonAA = 3;