// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/WidgetController/AttributesMenuWidgetController.h"


#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributesInfo.h"

void UAttributesMenuWidgetController::BroadcastInitialValue()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);
	check (AttributeInfo);

	for (auto Pair : AS->TagToAttributes)
	{
		BroadcastAttributeMenu (Pair.Key, Pair.Value());
	}
}

void UAttributesMenuWidgetController::BindCallbacksToDependencies()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);
	check (AttributeInfo);

	for (auto Pair : AS->TagToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
		[this, Pair](const FOnAttributeChangeData& Data)
			{
				BroadcastAttributeMenu (Pair.Key, Pair.Value());
			}
		);
	}
}

void UAttributesMenuWidgetController::BroadcastAttributeMenu(const FGameplayTag& AttributeTag,
	const FGameplayAttribute& Attribute) const
{
	FAuraAttributesInfo Info = AttributeInfo->FindAttributeTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}
