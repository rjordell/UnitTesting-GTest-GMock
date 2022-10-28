#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/Awards.h"
using awards::RankList;
using awards::AwardCeremonyActions;

class MockAwardCeremonyActions : public AwardCeremonyActions { 
	public: 
		MOCK_METHOD(void, playAnthem , (), (override)); 
		MOCK_METHOD(void, awardBronze, (std::string recepient), (override)); 
		MOCK_METHOD(void, awardSilver, (std::string recepient), (override)); 
		MOCK_METHOD(void, awardGold, (std::string recepient), (override)); 
		MOCK_METHOD(void, turnOffLightsAndGoHome, (), (override)); 
};

class StubRankList : public RankList {
	public:
		int counter = 0;
		std::string list[3];
		StubRankList() {
			list[0] = "a";
			list[1] = "b";
			list[2] = "c";
		}
		virtual std::string getNext() {return list[counter++];}
};

TEST(AwardsTest, testAwardsCeremony) {
	MockAwardsCeremonyActions mockActions;
	StubRankList stubList;
	EXPECT_CALL(mockActions, awardBronze("a"));
	performAwardCeremony(stubList, mockActions);
}
