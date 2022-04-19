#ifndef __INC_DATE_TESTS
#define __INC_DATE_TESTS

#include "unit.h"

#define __TEST_EST_BISSEXTILE       0
#define __TEST_DERNIER_JOUR_DU_MOIS 0
#define __TEST_DATE_VALIDE          0

#if __TEST_EST_BISSEXTILE
void testEstBissextile();
#endif

#if __TEST_DERNIER_JOUR_DU_MOIS
void testDernierJourDuMois();
#endif

#if __TEST_DATE_VALIDE
void testDateValide();
#endif

void allTests();

#endif /* __INC_DATE_TESTS */