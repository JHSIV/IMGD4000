// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Boids/FlockingManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFlockingManager() {}
// Cross Module References
	BOIDS_API UClass* Z_Construct_UClass_UFlockingManager_NoRegister();
	BOIDS_API UClass* Z_Construct_UClass_UFlockingManager();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_Boids();
// End Cross Module References
	void UFlockingManager::StaticRegisterNativesUFlockingManager()
	{
	}
	UClass* Z_Construct_UClass_UFlockingManager_NoRegister()
	{
		return UFlockingManager::StaticClass();
	}
	struct Z_Construct_UClass_UFlockingManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFlockingManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Boids,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlockingManager_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "FlockingManager.h" },
		{ "ModuleRelativePath", "FlockingManager.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFlockingManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFlockingManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFlockingManager_Statics::ClassParams = {
		&UFlockingManager::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFlockingManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFlockingManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFlockingManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFlockingManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFlockingManager, 4084130304);
	template<> BOIDS_API UClass* StaticClass<UFlockingManager>()
	{
		return UFlockingManager::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFlockingManager(Z_Construct_UClass_UFlockingManager, &UFlockingManager::StaticClass, TEXT("/Script/Boids"), TEXT("UFlockingManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFlockingManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
