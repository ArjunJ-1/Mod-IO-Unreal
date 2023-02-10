// Fill out your copyright notice in the Description page of Project Settings.


#include "Mod_IO_Widget.h"
#include "SSMenuWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"

void UMod_IO_Widget::NativeConstruct()
{
	Super::NativeConstruct();
	if(GEngine && GEngine->GameViewport)
	{
		MenuWidget = SNew(SSMenuWidget).OwningHUD(this);
		// add menu widget to viewport
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(MenuWidget.ToSharedRef()));
	}
	
}
