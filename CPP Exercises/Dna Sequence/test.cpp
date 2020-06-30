#include "pch.h"
#include "../DNA_sequence/DnaSequence.h"
#include "../DNA_sequence/InvalidNucleotid.h"

TEST(DnaSequenceFunctions, Slice) {
  DnaSequence dna1("AGGC");
  EXPECT_EQ(dna1.slice(1,2), "GG");
  EXPECT_TRUE(true);
}

TEST(DnaSequenceFunctions,pair ) {

	DnaSequence dna1("AGGCT");
	EXPECT_EQ(dna1.pair(), "TCCGA");
	EXPECT_TRUE(true);
}
/*
TEST(DnaSequenceFunctions, find) {

	DnaSequence dna1("AGGCT");
	EXPECT_EQ(dna1.find("GG"), 1);
	EXPECT_TRUE(true);
}

TEST(DnaSequenceFunctions, count) {

	DnaSequence dna1("AGGCGT");
	EXPECT_EQ(dna1.count("G"), 3);
	EXPECT_TRUE(true);
}


TEST(DnaSequenceFunctions, findConsensusSequences) {

	DnaSequence dna1("ATGATTTAGATGTAGTAAATGTGGTGA");
	EXPECT_EQ(dna1.findConsensusSequences (), 3);
	EXPECT_TRUE(true);
}
*/

