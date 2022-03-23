#include "conversionsTests.h"

void testEstUniteAnglo()
{
#if __TEST_EST_UNITE_ANGLO
	__BOOL estUniteAnglo(char unite);
	initUnitTest("estUniteAnglo");
	
	assertTrue(estUniteAnglo('i'));
	assertTrue(estUniteAnglo('f'));
	assertTrue(estUniteAnglo('y'));
	assertTrue(estUniteAnglo('m'));
	assertTrue(estUniteAnglo('l'));
	assertFalse(estUniteAnglo('a'));
	assertFalse(estUniteAnglo('x'));
	assertFalse(estUniteAnglo('z'));

	displayUnitTestReport();
#endif
}

void testConvertirAngloEnMm()
{
#if __TEST_CONVERTIR_ANGLO_EN_MM
	float convertirAngloEnMm(float mesure, char unite);
	initUnitTest("convertirAngloEnMm");
	
	assertFloatEquals(        0.0f, convertirAngloEnMm(  0.0f, 'i'), 0.005f);
	assertFloatEquals(     1016.0f, convertirAngloEnMm( 40.0f, 'i'), 0.005f);
	assertFloatEquals(     5080.0f, convertirAngloEnMm(200.0f, 'i'), 0.005f);
	assertFloatEquals(     6553.2f, convertirAngloEnMm( 21.5f, 'f'), 0.005f);
	assertFloatEquals(    36576.0f, convertirAngloEnMm( 40.0f, 'y'), 0.005f);
	assertFloatEquals( 34600896.0f, convertirAngloEnMm( 21.5f, 'm'), 0.005f);
	assertFloatEquals(193121280.0f, convertirAngloEnMm( 40.0f, 'l'), 0.005f);
	assertFloatEquals(        0.0f, convertirAngloEnMm( 21.5f, 'x'), 0.005f);

	displayUnitTestReport();
#endif
}

void allTests()
{
	testEstUniteAnglo();
	testConvertirAngloEnMm();
}