// Copyright James Mills - contact jcmills.developer@gmail.com


#include "CharacterSheetSaveData.h"

FCharacterSheetSaveData::FCharacterSheetSaveData() 
{
	Level = 0;
	HitDice = EDiceType::None;
	MaxHitPoints = 0;
	CurrentHitPoints = 0;
}

void FCharacterSheetSaveData::Save(const UCharacterSheetComponent* CharacterSheet) 
{
	Level = CharacterSheet->Level;
	HitDice = CharacterSheet->HitDice;
	MaxHitPoints = CharacterSheet->MaxHitPoints;
	CurrentHitPoints = CharacterSheet->CurrentHitPoints;

	Attributes.Empty();
	for (const auto Attribute : CharacterSheet->Attributes)
	{
		Attributes.AddUnique(Attribute);
	}
}

void FCharacterSheetSaveData::Load(UCharacterSheetComponent* CharacterSheet)
{
	CharacterSheet->Level = Level;
	CharacterSheet->HitDice = HitDice;
	CharacterSheet->MaxHitPoints = MaxHitPoints;
	CharacterSheet->CurrentHitPoints = CurrentHitPoints;

	CharacterSheet->Attributes.Empty();
	for(const auto Attribute : Attributes)
	{
		CharacterSheet->AddAttribute(Attribute);
	}
}
