// Copyright James Mills - contact jcmills.developer@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "EldoriaPlayerController.generated.h"

/**
 *
 */
UCLASS()
class ELDORIA_API AEldoriaPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Eldoria|Input")
	void ConfigureInputComponent(class UEnhancedInputComponent* EnhancedInput);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Eldoria|Input", meta = (AllowPrivateAccess = true))
	class UEldoriaInputConfig* InputConfig;

private:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

};
