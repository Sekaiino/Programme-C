#ifndef __INC_UNIT
#define __INC_UNIT

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <math.h>   // fabs
#include <stdio.h>  // printf, sprintf
#include <string.h> // memcmp, strrchr
#include <time.h>   // clock, CLOCKS_PER_SEC

#define __USE_STDBOOL 1 // Mettre � 0 si la biblioth�que <stdbool.h> n'est pas utilis�e

#if __USE_STDBOOL
# define __BOOL _Bool
#else
# define __BOOL int
#endif

#define MESSAGE_BUFFER_SIZE 200

char messageBuffer[MESSAGE_BUFFER_SIZE];

struct UnitTest {
	clock_t startTime;
	int runs;
	int failures;
} unitTest;

int compareArrays(const void *t1, const void *t2, int length, size_t datasize);
int compareFloatArrays(const float *t1, const float *t2, int length, float delta);
int checkIntArrayBetween(const int *t, int length, int lower, int upper);
int checkFloatArrayBetween(const float *t, int length, float lower, float upper, float delta);

/// <summary>
/// Initialise un test unitaire.
/// Cette op�ration est n�cessaire afin de permettre la collecte d'informations lors de l'ex�cution des assertions qui lui succ�dent.
/// </summary>
/// <remarks>
/// Les informations collect�es sont le nombre de tests effectu�s, le nombre de tests en �chec et le temps d'ex�cution des tests.
/// </remarks>
/// <param name="functionName">Le nom de la fonction test�e.</param>
void initUnitTest(const char *functionName);

/// <summary>
/// Affiche les informations collect�es pour un test unitaire.
/// </summary>
/// <remarks>
/// Cette op�ration n�cessite l'ex�cution pr�alable de la fonction 'initUnitTest'.
/// </remarks>
void displayUnitTestReport();

/// <summary>Signale l'�chec d'un test.</summary>
/// <param name="message">Un message expliquant la raison de l'�chec du test.</param>
#define fail(message) \
	unitTest.failures++; \
	printf("  FAILURE: %s\n", message); \
	printf("    at %s: %d\n", strrchr(__FILE__, '\\') + 1, __LINE__); \

/// <summary>
/// V�rifie qu'une condition est vraie.
/// Si la condition n'est pas vraie, le cas de test �choue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="condition">La condition � tester.</param>
#define assertTrue(condition) \
	unitTest.runs++; \
	if (!condition) { \
		fail("expected <true> but was <false>"); \
	}

/// <summary>
/// V�rifie qu'une condition est fausse.
/// Si la condition n'est pas fausse, le cas de test �choue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="condition">La condition � tester.</param>
#define assertFalse(condition) \
	unitTest.runs++; \
	if (condition) { \
		fail("expected <false> but was <true>"); \
	}

/// <summary>
/// V�rifie que deux caract�res sont �gaux.
/// Si les valeurs ne sont pas �gales, le cas de test �choue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">La valeur attendue.</param>
/// <param name="actual">La valeur re�ue.</param>
#define assertCharEquals(expected, actual) \
	{ \
		char lexpected = expected; \
		char lactual = actual; \
		unitTest.runs++; \
		if (lexpected != lactual) { \
			sprintf(messageBuffer, "expected <%c> but was <%c>", lexpected, lactual); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// V�rifie que deux caract�res ne sont pas �gaux.
/// Si les valeurs sont �gales, le cas de test �choue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">La valeur attendue.</param>
/// <param name="actual">La valeur re�ue.</param>
#define assertCharNotEquals(expected, actual) \
	{ \
		char lexpected = expected; \
		char lactual = actual; \
		unitTest.runs++; \
		if (lexpected == lactual) { \
			sprintf(messageBuffer, "expected <%c> but was <%c>", lexpected, lactual); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// V�rifie que deux valeurs enti�res sont �gales.
/// Si les valeurs ne sont pas �gales, le cas de test �choue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">La valeur attendue.</param>
/// <param name="actual">La valeur re�ue.</param>
#define assertIntEquals(expected, actual) \
	{ \
		int lexpected = expected; \
		int lactual = actual; \
		unitTest.runs++; \
		if (lexpected != lactual) { \
			sprintf(messageBuffer, "expected <%d> but was <%d>", lexpected, lactual); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// V�rifie que deux valeurs enti�res ne sont pas �gales.
/// Si les valeurs sont �gales, le cas de test �choue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">La valeur attendue.</param>
/// <param name="actual">La valeur re�ue.</param>
#define assertIntNotEquals(expected, actual) \
	{ \
		int lexpected = expected; \
		int lactual = actual; \
		unitTest.runs++; \
		if (lexpected == lactual) { \
			sprintf(messageBuffer, "expected <%d> but was <%d>", lexpected, lactual); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// V�rifie que deux valeurs r�elles sont �gales.
/// Si les valeurs ne sont pas �gales, le cas de test �choue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">La valeur attendue.</param>
/// <param name="actual">La valeur re�ue.</param>
/// <param name="delta">L'�cart maximum admis entre la valeur attendue et la valeur re�ue.</param>
#define assertFloatEquals(expected, actual, delta) \
	{ \
		float lexpected = expected; \
		float lactual = actual; \
		float ldelta = delta; \
		unitTest.runs++; \
		if (fabs(lexpected - lactual) > fabs(ldelta)) { \
			sprintf(messageBuffer, "expected <%g> but was <%g>", lexpected, lactual); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// V�rifie que deux valeurs r�elles ne sont pas �gales.
/// Si les valeurs sont �gales, le cas de test �choue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">La valeur attendue.</param>
/// <param name="actual">La valeur re�ue.</param>
/// <param name="delta">L'�cart minimum admis entre la valeur attendue et la valeur re�ue.</param>
#define assertFloatNotEquals(expected, actual, delta) \
	{ \
		float lexpected = expected; \
		float lactual = actual; \
		float ldelta = delta; \
		unitTest.runs++; \
		if (fabs(lexpected - lactual) <= fabs(ldelta)) { \
			sprintf(messageBuffer, "expected <%g> but was <%g>", lexpected, lactual); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// V�rifie que les �l�ments de deux tableaux de caract�res sont �gaux.
/// Si les valeurs ne sont pas �gales, le cas de test �choue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">Le tableau contenant les valeurs attendues.</param>
/// <param name="actual">Le tableau contenant les valeurs re�ues.</param>
/// <param name="length">La longueur des tableaux.</param>
#define assertCharArrayEquals(expected, actual, length) \
	{ \
		int index = compareArrays(expected, actual, length, sizeof(char)); \
		unitTest.runs++; \
		if (index >= 0) { \
			sprintf(messageBuffer, "arrays first differed at element [%d], expected <%c> but was <%c>", index, expected[index], actual[index]); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// V�rifie que les �l�ments de deux tableaux d'entiers sont �gaux.
/// Si les valeurs ne sont pas �gales, le cas de test �choue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">Le tableau contenant les valeurs attendues.</param>
/// <param name="actual">Le tableau contenant les valeurs re�ues.</param>
/// <param name="length">La longueur des tableaux.</param>
#define assertIntArrayEquals(expected, actual, length) \
	{ \
		int index = compareArrays(expected, actual, length, sizeof(int)); \
		unitTest.runs++; \
		if (index >= 0) { \
			sprintf(messageBuffer, "arrays first differed at element [%d], expected <%d> but was <%d>", index, expected[index], actual[index]); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// V�rifie que les �l�ments de deux tableaux de r�els sont �gaux.
/// Si les valeurs ne sont pas �gales, le cas de test �choue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">Le tableau contenant les valeurs attendues.</param>
/// <param name="actual">Le tableau contenant les valeurs re�ues.</param>
/// <param name="length">La longueur des tableaux.</param>
/// <param name="delta">L'�cart maximum admis entre la valeur attendue et la valeur re�ue.</param>
#define assertFloatArrayEquals(expected, actual, length, delta) \
	{ \
		int index = compareFloatArrays(expected, actual, length, delta); \
		unitTest.runs++; \
		if (index >= 0) { \
			sprintf(messageBuffer, "arrays first differed at element [%d], expected <%g> but was <%g>", index, expected[index], actual[index]); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// V�rifie que les �l�ments d'un tableau d'entiers sont compris dans un intervalle.
/// Si une valeur n'est pas comprise dans l'intervalle, le cas de test �choue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="actual">Le tableau contenant les valeurs re�ues.</param>
/// <param name="length">La longueur du tableau.</param>
/// <param name="lower">La borne inf�rieure inclusive de l'intervalle.</param>
/// <param name="upper">La borne sup�rieure inclusive de l'intervalle.</param>
#define assertIntArrayBetween(actual, length, lower, upper) \
	{ \
		int index = checkIntArrayBetween(actual, length, lower, upper); \
		unitTest.runs++; \
		if (index >= 0) { \
			sprintf(messageBuffer, "element <%d> at index [%d] not included in the range from <%d> to <%d>", actual[index], index, lower, upper); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// V�rifie que les �l�ments d'un tableau de r�els sont compris dans un intervalle.
/// Si une valeur n'est pas comprise dans l'intervalle, le cas de test �choue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="actual">Le tableau contenant les valeurs re�ues.</param>
/// <param name="length">La longueur du tableau.</param>
/// <param name="lower">La borne inf�rieure inclusive de l'intervalle.</param>
/// <param name="upper">La borne sup�rieure inclusive de l'intervalle.</param>
/// <param name="delta">L'exc�dent maximum admis entre la valeur re�ue et les bornes de l'intervalle.</param>
#define assertFloatArrayBetween(actual, length, lower, upper, delta) \
	{ \
		int index = checkFloatArrayBetween(actual, length, lower, upper, delta); \
		unitTest.runs++; \
		if (index >= 0) { \
			sprintf(messageBuffer, "element <%g> at index [%d] not included in the range from <%g> to <%g>", actual[index], index, lower, upper); \
			fail(messageBuffer); \
		} \
	}

#endif /* __INC_UNIT */