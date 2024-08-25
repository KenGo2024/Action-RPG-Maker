// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/WidgetController/AttributesMenuWidgetController.h"

#include "AuraGameplayTag.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributesInfo.h"

void UAttributesMenuWidgetController::BroadcastInitialValue()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);
	check (AttributeInfo);

	FAuraAttributesInfo Info = AttributeInfo->FindAttributeTag(FAuraGameplayTags::Get().Attributes_Primary_Strength);
	Info.AttributeValue = AS->GetStrength();
	AttributeInfoDelegate.Broadcast(Info);
}

void UAttributesMenuWidgetController::BindCallbacksToDependencies()
{
	/*UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);
	check (AttributeInfo);

	FAuraAttributesInfo Info = AttributeInfo->FindAttributeTag(FAuraGameplayTags::Get().Attributes_Primary_Strength);
	Info.AttributeValue = AS->GetStrength();
	AttributeInfoDelegate.Broadcast(Info);
	*/
}