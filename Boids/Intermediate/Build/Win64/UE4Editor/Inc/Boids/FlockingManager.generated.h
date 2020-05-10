// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BOIDS_FlockingManager_generated_h
#error "FlockingManager.generated.h already included, missing '#pragma once' in FlockingManager.h"
#endif
#define BOIDS_FlockingManager_generated_h

#define Boids_Source_Boids_FlockingManager_h_16_SPARSE_DATA
#define Boids_Source_Boids_FlockingManager_h_16_RPC_WRAPPERS
#define Boids_Source_Boids_FlockingManager_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define Boids_Source_Boids_FlockingManager_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFlockingManager(); \
	friend struct Z_Construct_UClass_UFlockingManager_Statics; \
public: \
	DECLARE_CLASS(UFlockingManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Boids"), NO_API) \
	DECLARE_SERIALIZER(UFlockingManager)


#define Boids_Source_Boids_FlockingManager_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUFlockingManager(); \
	friend struct Z_Construct_UClass_UFlockingManager_Statics; \
public: \
	DECLARE_CLASS(UFlockingManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Boids"), NO_API) \
	DECLARE_SERIALIZER(UFlockingManager)


#define Boids_Source_Boids_FlockingManager_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFlockingManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFlockingManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFlockingManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFlockingManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFlockingManager(UFlockingManager&&); \
	NO_API UFlockingManager(const UFlockingManager&); \
public:


#define Boids_Source_Boids_FlockingManager_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFlockingManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFlockingManager(UFlockingManager&&); \
	NO_API UFlockingManager(const UFlockingManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFlockingManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFlockingManager); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFlockingManager)


#define Boids_Source_Boids_FlockingManager_h_16_PRIVATE_PROPERTY_OFFSET
#define Boids_Source_Boids_FlockingManager_h_12_PROLOG
#define Boids_Source_Boids_FlockingManager_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Boids_Source_Boids_FlockingManager_h_16_PRIVATE_PROPERTY_OFFSET \
	Boids_Source_Boids_FlockingManager_h_16_SPARSE_DATA \
	Boids_Source_Boids_FlockingManager_h_16_RPC_WRAPPERS \
	Boids_Source_Boids_FlockingManager_h_16_INCLASS \
	Boids_Source_Boids_FlockingManager_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Boids_Source_Boids_FlockingManager_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Boids_Source_Boids_FlockingManager_h_16_PRIVATE_PROPERTY_OFFSET \
	Boids_Source_Boids_FlockingManager_h_16_SPARSE_DATA \
	Boids_Source_Boids_FlockingManager_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	Boids_Source_Boids_FlockingManager_h_16_INCLASS_NO_PURE_DECLS \
	Boids_Source_Boids_FlockingManager_h_16_ENHANCED_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BOIDS_API UClass* StaticClass<class UFlockingManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Boids_Source_Boids_FlockingManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
