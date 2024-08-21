// Copyright James Mills - contact jcmills.developer@gmail.com


#include "EldoriaSaveGame.h"

void UEldoriaSaveGame::Save(UCharacterSheetComponent* Character)
{
	CharacterSave.Save(Character);
}

void UEldoriaSaveGame::Load(UCharacterSheetComponent* Character)
{
	CharacterSave.Load(Character);
}
