#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyProjectMovementLibrary.generated.h"

class ACharacter;

UCLASS()
class MYPROJECT_API UMyProjectMovementLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Use after Crouch() while falling so lateral speed is not capped by crouch walk speed. */
	UFUNCTION(BlueprintCallable, Category = "Movement", meta = (DefaultToSelf = "Character"))
	static void RestoreAirborneCrouchMaxWalkSpeed(ACharacter* Character, float NewMaxWalkSpeed = 900.f);
};
