#include "dateTests.h"

void testEstBissextile()
{
#if __TEST_EST_BISSEXTILE
	__BOOL estBissextile(int annee);
	initUnitTest("estBissextile");
	
	assertTrue(estBissextile(   0));
	assertTrue(estBissextile(2000));
	assertTrue(estBissextile(2016));
	assertTrue(estBissextile(2020));
	assertTrue(estBissextile(2032));
	assertFalse(estBissextile(1900));
	assertFalse(estBissextile(2011));
	assertFalse(estBissextile(2018));
	assertFalse(estBissextile(2100));
	assertFalse(estBissextile(2200));

	displayUnitTestReport();
#endif
}

void testDernierJourDuMois()
{
#if __TEST_DERNIER_JOUR_DU_MOIS
	int dernierJourDuMois(int mois, int annee);
	initUnitTest("dernierJourDuMois");
	
	assertIntEquals( 0, dernierJourDuMois( 0, 2018));
	assertIntEquals(31, dernierJourDuMois( 1, 2018));
	assertIntEquals(28, dernierJourDuMois( 2, 2018));
	assertIntEquals(29, dernierJourDuMois( 2, 2016));
	assertIntEquals(31, dernierJourDuMois( 3, 2018));
	assertIntEquals(30, dernierJourDuMois( 4, 2018));
	assertIntEquals(31, dernierJourDuMois( 5, 2018));
	assertIntEquals(30, dernierJourDuMois( 6, 2018));
	assertIntEquals(31, dernierJourDuMois( 7, 2018));
	assertIntEquals(31, dernierJourDuMois( 8, 2018));
	assertIntEquals(30, dernierJourDuMois( 9, 2018));
	assertIntEquals(31, dernierJourDuMois(10, 2018));
	assertIntEquals(30, dernierJourDuMois(11, 2018));
	assertIntEquals(31, dernierJourDuMois(12, 2018));
	assertIntEquals( 0, dernierJourDuMois(13, 2018));

	displayUnitTestReport();
#endif
}

void testDateValide()
{
#if __TEST_DATE_VALIDE
	__BOOL dateValide(int jour, int mois, int annee);
	initUnitTest("dateValide");
	
	assertTrue(dateValide( 1,  1, 1700));
	assertTrue(dateValide(31,  1, 2014));
	assertTrue(dateValide(28,  2, 2015));
	assertTrue(dateValide(29,  2, 2016));
	assertTrue(dateValide(31,  3, 2020));
	assertTrue(dateValide(30,  4, 2021));
	assertTrue(dateValide(31,  5, 2022));
	assertTrue(dateValide(30,  6, 2023));
	assertTrue(dateValide(31,  7, 2024));
	assertTrue(dateValide(31,  8, 2025));
	assertTrue(dateValide(30,  9, 2026));
	assertTrue(dateValide(31, 10, 2027));
	assertTrue(dateValide(30, 11, 2028));
	assertTrue(dateValide( 1, 12, 2200));
	assertTrue(dateValide(31, 12, 2200));
	assertFalse(dateValide( 0,  1, 1700));
	assertFalse(dateValide(32,  1, 2014));
	assertFalse(dateValide(29,  2, 2015));
	assertFalse(dateValide(30,  2, 2016));
	assertFalse(dateValide(32,  3, 2020));
	assertFalse(dateValide(31,  4, 2021));
	assertFalse(dateValide(32,  5, 2022));
	assertFalse(dateValide(31,  6, 2023));
	assertFalse(dateValide(32,  7, 2024));
	assertFalse(dateValide(32,  8, 2025));
	assertFalse(dateValide(31,  9, 2026));
	assertFalse(dateValide(32, 10, 2027));
	assertFalse(dateValide(31, 11, 2028));
	assertFalse(dateValide(-1, 12, 2200));
	assertFalse(dateValide(32, 12, 2200));

	displayUnitTestReport();
#endif
}

void allTests()
{
	testEstBissextile();
	testDernierJourDuMois();
	testDateValide();
}