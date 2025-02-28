#pragma once

#include "../ZRoomCommand.h"

class ActorCutsceneEntry
{
public:
	int16_t priority;
	int16_t length;
	int16_t unk4;
	int16_t unk6;
	int16_t additionalCutscene;
	uint8_t sound;
	uint8_t unkB;
	int16_t unkC;
	uint8_t unkE;
	uint8_t letterboxSize;

	ActorCutsceneEntry(std::vector<uint8_t> rawData, int rawDataIndex);
};

class SetActorCutsceneList : public ZRoomCommand
{
public:
	SetActorCutsceneList(ZRoom* nZRoom, std::vector<uint8_t> rawData, int rawDataIndex);
	~SetActorCutsceneList();

	std::string GenerateSourceCodePass1(std::string roomName, int baseAddress) override;
	std::string GenerateSourceCodePass2(std::string roomName, int baseAddress) override;
	std::string GetCommandCName() override;
	std::string GenerateExterns() override;
	RoomCommand GetRoomCommand() override;
	int GetRawDataSize() override;

private:
	std::vector<ActorCutsceneEntry*> cutscenes;
	uint32_t segmentOffset;
};
