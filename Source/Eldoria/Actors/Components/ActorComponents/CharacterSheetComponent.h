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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (UIMin = "1", UIMax = "30", ClampMin = "1", ClampMax = "30"))
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

public:
	// Sets default values for this component's properties
	UCharacterSheetComponent();

public:
	UFUNCTION(BlueprintPure)
	static FCharacterAttribute MakeAttribute(FName ID, bool bIsProficient, UPARAM(meta = (Bitmask, BitmaskEnum = EAttributeCapabilities))int32 Capabilities);

public:
	UFUNCTION(BlueprintPure, Category = "Eldoria|Character|Stats", meta = (CompactNodeTitle = "Attribute"))
	void FindAttribute(FName ID, FCharacterAttribute& Attribute, bool& bFound);

	UFUNCTION(BlueprintPure, Category = "Eldoria|Character|Stats", DisplayName = "Level", meta = (CompactNodeTitle = "Level"))
	int32 GetLevel() const;

	UFUNCTION(BlueprintCallable, Category = "Eldoria|Character|Stats")
	void AddAttribute(FCharacterAttribute Attribute);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = true, TitleProperty = "ID"))
	TArray<FCharacterAttribute> Attributes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true, ClampMin = "1", ClampMax = "30", UIMin = "1", UIMax = "30"))
	int32 Level;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	EDiceType HitDice;

};
