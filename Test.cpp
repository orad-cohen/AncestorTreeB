#include "doctest.h"
#include "FamilyTree.hpp"


#include <string>
using namespace std;

TEST_CASE("Relations")
{
    family::Tree T ("Moshe"); // Moshe is the "root" of the tree (the youngest person).
	T.addFather("Moshe", "Yaakov")   // Tells the tree that the father of Moshe is Yaakov.
	 .addMother("Moshe", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
    CHECK(T.relation("Yaakov") == "father");
    CHECK(T.relation("Yaako") == "unrelated");
    CHECK(T.relation("Yaak") == "unrelated");
    CHECK(T.relation("Yaa") == "unrelated");
    CHECK(T.relation("Ya") == "unrelated");
    CHECK(T.relation("Y") == "unrelated");
    CHECK(T.relation("Yakov") == "unrelated");
    CHECK(T.relation("YAAKOV") == "unrelated");
    CHECK(T.relation("Rachel") == "mother");
    CHECK(T.relation("Rivka") == "grandmother");
    CHECK(T.relation("Avraham") == "great-grandfather");
    CHECK(T.relation("Terah") == "great-great-grandfather");
    CHECK(T.relation("abc") == "unrelated");
    CHECK(T.relation("Moshe") == "me");
    CHECK(T.relation("M") == "unrelated");
    CHECK(T.relation("Mo") == "unrelated");
    CHECK(T.relation("Mos") == "unrelated");
    CHECK(T.relation("Mosh") == "unrelated");
    CHECK(T.relation("MOSHE") == "unrelated");
    CHECK(T.relation("MOSHe") == "unrelated");
    CHECK(T.relation("MOSH3") == "unrelated");
    CHECK(T.relation("M0SHE") == "unrelated");
    CHECK(T.relation("MOShE") == "unrelated");
    CHECK(T.relation("MOsHE") == "unrelated");
    CHECK(T.relation("mOSHE") == "unrelated");
    CHECK(T.relation("moSHE") == "unrelated");
    CHECK(T.relation("mosHE") == "unrelated");
    CHECK(T.relation("moshE") == "unrelated");
    CHECK(T.relation("moshee") == "unrelated");
    CHECK(T.find("mother") == "Rachel");
    CHECK(T.find("father") == "Yaakov");
    CHECK(T.find("grandmother") == "Rivka");
    CHECK(T.find("great-grandfather") == "Avraham");
    CHECK(T.find("great-great-grandfather") == "Terah");
     T.remove("Avraham"); //Removes everyone in the tree from Avraham(included) and forward(his parents and so on).
    CHECK(T.relation("Terah") == "unrelated"); //Because we removed his son(Avraham).
     
     //The checks above throw exceptions.
    CHECK_THROWS(T.find("mothe"));
    CHECK_THROWS(T.find("motherr") );
    CHECK_THROWS(T.find("mothera") );
    CHECK_THROWS(T.find("mothere") );
    CHECK_THROWS(T.find("other") );
    CHECK_THROWS(T.find("fatherr") );
    CHECK_THROWS(T.find("Fatherr") );
    CHECK_THROWS(T.find("Father") );
    CHECK_THROWS(T.find("fAther") );
    CHECK_THROWS(T.find("fATher") );
    CHECK_THROWS(T.find("fATHer") );
    CHECK_THROWS(T.find("fATHEr") );
    CHECK_THROWS(T.find("moth") );
    CHECK_THROWS(T.find("mot") );
    CHECK_THROWS(T.find("mo") );
    CHECK_THROWS(T.find("m"));
    CHECK_THROWS(T.find("MOTHE") );
    CHECK_THROWS(T.find("MOTHER") );
    CHECK_THROWS(T.find("MOTHERR") );
    CHECK_THROWS(T.find("MOTHEr") );
    CHECK_THROWS(T.find("MOTHErr") );
    CHECK_THROWS(T.find("MOTHer") );
    CHECK_THROWS(T.find("MOTher") );
    CHECK_THROWS(T.find("MOther") );
    CHECK_THROWS(T.find("Mother") );
    CHECK_THROWS(T.find("mOTHER") );
    CHECK_THROWS(T.find("moTHER") );
    CHECK_THROWS(T.find("motHER") );
    CHECK_THROWS(T.find("mothER") );
    CHECK_THROWS(T.find("motheR") );
    CHECK_THROWS(T.find("motheeR") );
    CHECK_THROWS(T.find("MOTH") );
    CHECK_THROWS(T.find("MOT") );
    CHECK_THROWS(T.find("MO") );
    CHECK_THROWS(T.find("M") );
    CHECK_THROWS(T.find("A") );
    CHECK_THROWS(T.find("greatgreat-grandfather") ); //52
    CHECK_THROWS(T.find("great-great-grandfatherr") );
    CHECK_THROWS(T.find("great-great-grandfatherR") );
    CHECK_THROWS(T.find("great-great-grandfatherr") );
    CHECK_THROWS(T.find("Great-great-grandfather") );
    CHECK_THROWS(T.find("great-Great-grandfather") );
    CHECK_THROWS(T.find("gReat-great-grandfather") );
    CHECK_THROWS(T.find("grEat-great-grandfather") );
    CHECK_THROWS(T.find("greAt-great-grandfather") );
    CHECK_THROWS(T.find("greaT-great-grandfather") );
    CHECK_THROWS(T.find("great-gReat-grandfather") );
    CHECK_THROWS(T.find("great-grEat-grandfather") );
    CHECK_THROWS(T.find("great-greAt-grandfather") );
    CHECK_THROWS(T.find("great-greaT-grandfather") );
    CHECK_THROWS(T.find("great-great-Grandfather") );
    CHECK_THROWS(T.find("great-great-gRandfather") );
    CHECK_THROWS(T.find("great-great-grAndfather") );
    CHECK_THROWS(T.find("great-great-graNdfather") );
    CHECK_THROWS(T.find("great-great-granDfather") );
    CHECK_THROWS(T.find("great-great-grandFather") );
    CHECK_THROWS(T.find("great-great-grandfAther") );
    CHECK_THROWS(T.find("great-great-grandfaTher") );
    CHECK_THROWS(T.find("great-great-grandfatHer") );
    CHECK_THROWS(T.find("great-great-grandfathEr") );
    CHECK_THROWS(T.find("great-great-grandfatheR") );
    CHECK_THROWS(T.find("great-grandfaTher") );
    CHECK_THROWS(T.find("Great-grandfather") );
    CHECK_THROWS(T.find("gReat-grandfather") );
    CHECK_THROWS(T.find("grEat-grandfather") );
    CHECK_THROWS(T.find("greAt-grandfather") );
    CHECK_THROWS(T.find("greaT-grandfather") );
    CHECK_THROWS(T.find("great-Grandfather") );
    CHECK_THROWS(T.find("great-gRandfather") );
    CHECK_THROWS(T.find("great-grAndfather") );
    CHECK_THROWS(T.find("great-graNdfather") );
    CHECK_THROWS(T.find("great-granDfather") );
    CHECK_THROWS(T.find("great-grandFather") );
    CHECK_THROWS(T.find("great-grandfAther") );
    CHECK_THROWS(T.find("great-grandfaTher") );
    CHECK_THROWS(T.find("great-grandfatHer") );
    CHECK_THROWS(T.find("great-grandfathEr") );
    CHECK_THROWS(T.find("great-grandfatheR") );
    CHECK_THROWS(T.find("great-grandfatherr") );
    CHECK_THROWS(T.find("greatgrandfather") );
    CHECK_THROWS(T.find("grandfatherr") );
    CHECK_THROWS(T.find("grandfatheR") );
    CHECK_THROWS(T.find("grandfathEr") );
    CHECK_THROWS(T.find("grandfatHer") );
    CHECK_THROWS(T.find("grandfaTher") );
    CHECK_THROWS(T.find("grandfAther") );
    CHECK_THROWS(T.find("grandFather") );
    CHECK_THROWS(T.find("granDfather") );
    CHECK_THROWS(T.find("graNdfather") );
    CHECK_THROWS(T.find("grAndfather") );
    CHECK_THROWS(T.find("graNdfather") );
    CHECK_THROWS(T.find("grAndfather") );
    CHECK_THROWS(T.find("gRandfather") );
    CHECK_THROWS(T.find("Grandfather") );
    CHECK_THROWS(T.find("GGrandfather") );
    CHECK_THROWS(T.find("grand-father") );
    CHECK_THROWS(T.find("greatfather") );
    CHECK_THROWS(T.find("great-father") );
    CHECK_THROWS(T.find("great-grand") );
    CHECK_THROWS(T.find("great-great") );
    CHECK_THROWS(T.find("grandmotherr") );
}
