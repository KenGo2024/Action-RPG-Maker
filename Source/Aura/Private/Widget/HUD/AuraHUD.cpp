// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/HUD/AuraHUD.h"
#include "Widget/AuraUserWidget.h"
#include "Widget/WidgetController/AttributesMenuWidgetController.h"
#include "Widget/WidgetController/OverlayWidgetController.h"


UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController;
}

UAttributesMenuWidgetController* AAuraHUD::GetAttributesMenuWidgetController(const FWidgetControllerParams& WCParams)
{
	if (AttributesMenuWidgetController ==nullptr)
	{
		AttributesMenuWidgetController = NewObject<UAttributesMenuWidgetController>(this, AttributesMenuWidgetControllerClass);
		AttributesMenuWidgetController->SetWidgetControllerParams(WCParams);
		AttributesMenuWidgetController->BindCallbacksToDependencies();
	}
	return AttributesMenuWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf (OverlayWidgetClass, TEXT("OverlayWidgetClss is null, Please fill out BP_AuraHUD"));
	checkf (OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass is null, Please fill out BP_AuraHUD"));
	
	UUserWidget* Widget = CreateWidget<UAuraUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);
	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValue();
	OverlayWidget->AddToViewport();
}


