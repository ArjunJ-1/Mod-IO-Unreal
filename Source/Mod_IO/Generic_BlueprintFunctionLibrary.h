// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Generic.h"
#include "Generic_BlueprintFunctionLibrary.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_DELEGATE(FunctionDelegate);

UCLASS()
class MOD_IO_API UGeneric_BlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Generic Utils")
	static void InvokeFunction(FunctionDelegate Func)
	{
		AsyncTask(ENamedThreads::AnyHiPriThreadNormalTask, [=] { Common_Utils::GenericFunc(Func.ExecuteIfBound()); });
	}
};
