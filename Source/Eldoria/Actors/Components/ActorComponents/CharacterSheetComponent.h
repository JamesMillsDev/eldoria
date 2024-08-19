// Copyright James Mills - contact jcmills.developer@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterSheetComponent.generated.h"

USTRUCT(BlueprintType)
struct FCharacterAttribute
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName ID;

};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ELDORIA_API UCharacterSheetComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCharacterSheetComponent();

public:
	UFUNCTION(BlueprintPure, Category = "Eldoria|Character|Stats", meta = (CompactNodeTitle = "Attribute"))
	void FindAttribute(FName ID, FCharacterAttribute& Attribute, bool& bFound);

	UFUNCTION(BlueprintPure, Category = "Eldoria|Character|Stats", DisplayName = "Level", meta = (CompactNodeTitle = "Level"))
	int32 GetLevel() const;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	TArray<FCharacterAttribute> Attributes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true, ClampMin = "1", ClampMax = "30", UIMin = "1", UIMax = "30"))
	int32 Level;

};
