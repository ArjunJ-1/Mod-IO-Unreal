// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Mod_IO_Widget.generated.h"

/**
 * 
 */
UCLASS()
class MOD_IO_API UMod_IO_Widget : public UUserWidget
{
	GENERATED_BODY()
	TSharedPtr<class SSMenuWidget> MenuWidget;
	TSharedPtr<class SWidget> MenuWidgetContainer;

	virtual void NativeConstruct() override;
};
