// Copyright James Mills - contact jcmills.developer@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Eldoria/GlobalEnums.h"
#include "CharacterSheetComponent.generated.h"

USTRUCT(BlueprintType)
struct FCharacterAttribute
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName ID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bIsProficient;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Bitmask, BitmaskEnum = EAttributeCapabilities))
	int32 AttributeCapabilities;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (UIMin = "1", UIMax = "20", ClampMin = "1", ClampMax = "20"))
	int32 Value;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = "bIsProficient", EditConditionHides))
	FName ModifierID;

public:
	FCharacterAttribute();

	FCharacterAttribute(FName Name);

public:
	bool operator==(const FCharacterAttribute& RHS) const;
	bool operator!=(const FCharacterAttribute& RHS) const;

};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ELDORIA_API UCharacterSheetComponent : public UActorComponent
{
	GENERATED_BODY()

	friend struct FCharacterSheetSaveData;

public:
	// Sets default values for this component's properties
	UCharacterSheetComponent();

public:
	UFUNCTION(BlueprintPure)
	static FCharacterAttribute MakeAttribute(FName ID, bool bIsProficient, UPARAM(meta = (Bitmask, BitmaskEnum = EAttributeCapabilities))int32 Capabilities);

public:
	UFUNCTION(BlueprintPure, Category = "Eldoria|Character|Stats", DisplayName = "Level", meta = (CompactNodeTitle = "Level"))
	int32 GetLevel() const;

	UFUNCTION(BlueprintPure, Category = "Eldoria|Character|Stats", DisplayName = "Hit Die", meta = (CompactNodeTitle = "Hit Die"))
	EDiceType GetHitDice() const;

	UFUNCTION(BlueprintPure, Category = "Eldoria|Character|Stats", DisplayName = "Character Attributes", meta = (CompactNodeTitle = "Character Attributes"))
	TArray<FCharacterAttribute> GetCharacterAttributes();

	UFUNCTION(BlueprintCallable, Category = "Eldoria|Character|Stats")
	void AddAttribute(FCharacterAttribute Attribute);

	UFUNCTION(BlueprintPure, Category = "Eldoria|Character|Stats", meta = (CompactNodeTitle = "Attribute"))
	void FindAttribute(FName ID, FCharacterAttribute& Attribute, bool& bFound);

	UFUNCTION(BlueprintPure, Category = "Eldoria|Character|Stats")
	void FindAttributesWithCapability(UPARAM(meta = (Bitmask, BitmaskEnum = EAttributeCapabilities)) int32 Capability, TArray<FCharacterAttribute>& CapableAttributes, bool& bFound);

	UFUNCTION(BlueprintCallable, Category = "Eldoria|Character|Stats")
	void SetHitPoints();

	UFUNCTION(BlueprintPure, Category = "Eldoria|Character|Stats", DisplayName = "Max Hit Points", meta = (CompactNodeTitle = "Max Hit Points"))
	int32 GetMaxHitPoints() const;

	UFUNCTION(BlueprintPure, Category = "Eldoria|Character|Stats", DisplayName = "Current Hit Points", meta = (CompactNodeTitle = "Current Hit Points"))
	int32 GetCurrentHitPoints() const;

private:
	UPROPERTY(EditDefaultsOnly, meta = (TitleProperty = "ID"))
	TArray<FCharacterAttribute> Attributes;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "1", ClampMax = "20", UIMin = "1", UIMax = "20"))
	int32 Level;

	UPROPERTY(EditDefaultsOnly)
	EDiceType HitDice;

	UPROPERTY(VisibleAnywhere)
	int32 MaxHitPoints;

	UPROPERTY(VisibleAnywhere)
	int32 CurrentHitPoints;

};
