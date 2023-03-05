#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "func.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Get GC Content", "verification")
{
	string dna1 = "AGCTATAG";
	string dna2 = "CGCTATAG";
	REQUIRE(get_gc_content(dna1) == 0.375);
	REQUIRE(get_gc_content(dna2) == 0.50);
}

TEST_CASE("Verify Reverse String", "verification")
{
	string dna1 = "AGCTATAG";
	string dna2 = "CGCTATAG";
	REQUIRE(get_reverse_string(dna1) == "GATATCGA");
	REQUIRE(get_reverse_string(dna2) == "GATATCGC");
}

TEST_CASE("Verify Get DNA Complement", "verification")
{
	string dna1 = "AAAACCCGGT";
	string dna2 = "CCCGGAAAAT";
	REQUIRE(get_dna_complement(dna1) == "ACCGGGTTTT");
	REQUIRE(get_dna_complement(dna2) == "ATTTTCCGGG");
}