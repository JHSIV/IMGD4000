// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BOIDS_BoidsGameModeBase_generated_h
#error "BoidsGameModeBase.generated.h already included, missing '#pragma once' in BoidsGameModeBase.h"
#endif
#define BOIDS_BoidsGameModeBase_generated_h

#define Boids_Source_Boids_BoidsGameModeBase_h_15_SPARSE_DATA
#define Boids_Source_Boids_BoidsGameModeBase_h_15_RPC_WRAPPERS
#define Boids_Source_Boids_BoidsGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define Boids_Source_Boids_BoidsGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABoidsGameModeBase(); \
	friend struct Z_Construct_UClass_ABoidsGameModeBase_Statics; \
public: \
	DECLARE_CLASS(ABoidsGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Boids"), NO_API) \
	DECLARE_SERIALIZER(ABoidsGameModeBase)


#define Boids_Source_Boids_BoidsGameModeBase_h_15_INCLASS \
private: \
	static void StaticRegisterNativesABoidsGameModeBase(); \
	friend struct Z_Construct_UClass_ABoidsGameModeBase_Statics; \
public: \
	DECLARE_CLASS(ABoidsGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Boids"), NO_API) \
	DECLARE_SERIALIZER(ABoidsGameModeBase)


#define Boids_Source_Boids_BoidsGameModeBase_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABoidsGameModeBase(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABoidsGameModeBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoidsGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoidsGameModeBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoidsGameModeBase(ABoidsGameModeBase&&); \
	NO_API ABoidsGameModeBase(const ABoidsGameModeBase&); \
public:


#define Boids_Source_Boids_BoidsGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoidsGameModeBase(ABoidsGameModeBase&&); \
	NO_API ABoidsGameModeBase(const ABoidsGameModeBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoidsGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoidsGameModeBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABoidsGameModeBase)


#define Boids_Source_Boids_BoidsGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__AgentMesh() { return STRUCT_OFFSET(ABoidsGameModeBase, AgentMesh); }


#define Boids_Source_Boids_BoidsGameModeBase_h_12_PROLOG
#define Boids_Source_Boids_BoidsGameModeBase_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Boids_Source_Boids_BoidsGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	Boids_Source_Boids_BoidsGameModeBase_h_15_SPARSE_DATA \
	Boids_Source_Boids_BoidsGameModeBase_h_15_RPC_WRAPPERS \
	Boids_Source_Boids_BoidsGameModeBase_h_15_INCLASS \
	Boids_Source_Boids_BoidsGameModeBase_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Boids_Source_Boids_BoidsGameModeBase_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Boids_Source_Boids_BoidsGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	Boids_Source_Boids_BoidsGameModeBase_h_15_SPARSE_DATA \
	Boids_Source_Boids_BoidsGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Boids_Source_Boids_BoidsGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
	Boids_Source_Boids_BoidsGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BOIDS_API UClass* StaticClass<class ABoidsGameModeBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Boids_Source_Boids_BoidsGameModeBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
