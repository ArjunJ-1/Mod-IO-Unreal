// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Generic_BlueprintFunctionLibrary.h"
#include "SlateBasics.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class MOD_IO_API SSMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSMenuWidget){}
	SLATE_ARGUMENT(TWeakObjectPtr<class UMod_IO_Widget> , OwningHUD);
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	/** The HUD that created this widget */
	TWeakObjectPtr<class UMod_IO_Widget> OwningHUD;
	virtual bool SupportsKeyboardFocus() const override {return true;}
	FText GetTitleText() const;
	void SetText(FText Text);
	FText TitleText = FText::FromString("mod.io Test");
	FReply OnButtonClicked();
};
