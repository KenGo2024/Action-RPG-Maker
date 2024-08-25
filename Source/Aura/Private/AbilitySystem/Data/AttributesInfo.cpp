// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Data/AttributesInfo.h"

FAuraAttributesInfo UAttributesInfo::FindAttributeTag(const FGameplayTag& AttributesTag, bool bLogNotFound) const
{
	for (const FAuraAttributesInfo& Info : AttributeInfo)
	{
		if (Info.AttributesTag.MatchesTagExact(AttributesTag))
		{
			return Info;
		}
	}
	if (bLogNotFound)
	{
		UE_LOG(
			LogTemp,
			Error,
			TEXT(
				"Can't find Info for AttributeTag [%s] on AttributeInfo [%s]"),
				*AttributesTag.ToString(),
				*GetNameSafe(this)
			);
	}
	return FAuraAttributesInfo();
}
