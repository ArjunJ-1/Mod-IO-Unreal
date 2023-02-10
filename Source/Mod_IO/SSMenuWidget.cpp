// Fill out your copyright notice in the Description page of Project Settings.


#include "SSMenuWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSMenuWidget::Construct(const FArguments& InArgs)
{
	const FText ButtonText = FText::FromString("Click Me!");
	const FMargin TextPadding = FMargin(500.f, 300.f);
	const FMargin ButtonPadding = FMargin(500.f, 400.f);

	FSlateFontInfo Font = FCoreStyle::GetDefaultFontStyle("Regular", 24);
	const FString ImagePath = FPaths::ProjectContentDir() / "pepe.png";
	
	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.Image(FCoreStyle::Get().GetBrush("GenericWhiteBox"))
			.ColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f, 0.5f))
		]
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(TextPadding)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			[
				SNew(STextBlock)
				.Font(Font)
				.Text(this, &SSMenuWidget::GetTitleText)
			]
		]
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(ButtonPadding)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			[
				SNew(SButton)
				.OnClicked(this, &SSMenuWidget::OnButtonClicked)
				[
					SNew(STextBlock)
					.Font(Font)
					.Text(ButtonText)
				]
			]
		]
		+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		[
			SNew(SImage)
			.Image(new FSlateImageBrush(FName(*ImagePath), FVector2D(250, 250)))
		]
	];
}


FText SSMenuWidget::GetTitleText() const
{
	return TitleText;
}

void SSMenuWidget::SetText(FText Text)
{
	TitleText = Text;
}

FReply SSMenuWidget::OnButtonClicked()
{
	SetText(FText::FromString("Howdy!"));
	return FReply::Handled();
}


END_SLATE_FUNCTION_BUILD_OPTIMIZATION
