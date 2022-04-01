#ifndef __INC_CONVERSIONS_TESTS
#define __INC_CONVERSIONS_TESTS

#include "unit.h"

#define __TEST_EST_UNITE_ANGLO       1
#define __TEST_CONVERTIR_ANGLO_EN_MM 0

#if __TEST_EST_UNITE_ANGLO
void testEstUniteAnglo();
#endif

#if __TEST_CONVERTIR_ANGLO_EN_MM
void testConvertirAngloEnMm();
#endif

void allTests();

#endif /* __INC_CONVERSIONS_TESTS */