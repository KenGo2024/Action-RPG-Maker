// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AuraInputConfig.h"
#include "EnhancedInputComponent.h"
#include "AuraEnhancedInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:

	template<class UserClass, typename PressFunc, typename ReleaseFunc, typename HoldFunc>
	void BindAbilityAction(const UAuraInputConfig* InputConfig, UserClass* Object, PressFunc Press, ReleaseFunc Release, HoldFunc Hold);
};

template <class UserClass, typename PressFunc, typename ReleaseFunc, typename HoldFunc>
void UAuraEnhancedInputComponent::BindAbilityAction(const UAuraInputConfig* InputConfig, UserClass* Object,
	PressFunc Press, ReleaseFunc Release, HoldFunc Hold)
{
	check (InputConfig);
	for (const FAuraInputAction& InputAction : InputConfig->AbilityInputActions)
	{
		if (InputAction.InputAction && InputAction.InputTag.IsValid())
		{
			if (Press)
			{
				BindAction(InputAction.InputAction, ETriggerEvent::Started, Object, Press, InputAction.InputTag);
			}
			
			if (Hold)
			{
				BindAction(InputAction.InputAction, ETriggerEvent::Triggered, Object, Hold, InputAction.InputTag);
			}

			if (Release)
			{
				BindAction(InputAction.InputAction, ETriggerEvent::Completed, Object, Release, InputAction.InputTag);
			}
		}
	}
}
