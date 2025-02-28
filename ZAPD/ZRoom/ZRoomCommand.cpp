#include "ZRoomCommand.h"
#include "StringHelper.h"

using namespace std;

ZRoomCommand::ZRoomCommand(ZRoom* nZRoom, std::vector<uint8_t> rawData, int rawDataIndex)
{
	cmdID = (RoomCommand)rawData[rawDataIndex];
	cmdAddress = rawDataIndex;
	zRoom = nZRoom;
}

string ZRoomCommand::GenerateSourceCodePass1(string roomName, int baseAddress)
{
	return StringHelper::Sprintf("0x%02X,", (uint8_t)cmdID);
}

string ZRoomCommand::GenerateSourceCodePass2(string roomName, int baseAddress)
{
	return "";
}

string ZRoomCommand::GenerateSourceCodePass3(string roomName)
{
	return "";
}

string ZRoomCommand::GenerateExterns()
{
	return "";
}

std::string ZRoomCommand::Save()
{
	return std::string();
}

std::string ZRoomCommand::PreGenSourceFiles()
{
	return std::string();
}

int32_t ZRoomCommand::GetRawDataSize()
{
	return 8;
}

string ZRoomCommand::GetCommandCName()
{
	return "SCmdBase";
}

RoomCommand ZRoomCommand::GetRoomCommand()
{
	return RoomCommand::Error;
}