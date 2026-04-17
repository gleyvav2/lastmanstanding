#include "MyProjectMovementLibrary.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMyProjectMovementLibrary::RestoreAirborneCrouchMaxWalkSpeed(ACharacter* Character, float NewMaxWalkSpeed)
{
	if (!Character)
	{
		return;
	}

	if (UCharacterMovementComponent* MoveComp = Character->GetCharacterMovement())
	{
		MoveComp->MaxWalkSpeed = NewMaxWalkSpeed;
	}
}
