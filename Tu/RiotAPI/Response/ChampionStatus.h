
#ifndef __RiotAPI_Response_ChampionStatus_h__
#define __RiotAPI_Response_ChampionStatus_h__
#include RiotAPI/Response/APIResponse.h

NS_RIOT_BEGIN

class ChampionStatus : public APIResponse {
public:
    ChampionStatus(const std::string & json);
    ChampionStatus(const char * json);
    ChampionStatus(bool active, bool botEnabled, bool botMmEnabled, bool freeToPlay, long id, bool rankedPlayEnabled);
    bool isActive();
    bool isBotEnabled();
    bool isBotMmEnabled();
    bool isFreeToPlay();
    long getId();
    bool isRankedPlayEnabled();
private:
    bool _active;
    bool _botEnabled;
    bool _botMmEnabled;
    bool _freeToPlay;
    long _id;
    bool _rankedPlayEnabled;
};

NS_RIOT_END

#endif // __RiotAPI_Response_ChampionStatus_h__