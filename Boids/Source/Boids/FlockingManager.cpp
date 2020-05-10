// Fill out your copyright notice in the Description page of Project Settings.


#include "FlockingManager.h"

#define AGENT_COUNT 10
#define RULE1_WEIGHT 0.01
#define RULE2_WEIGHT 1
#define RULE3_WEIGHT 1

void UFlockingManager::Init(UWorld *world, UStaticMeshComponent *mesh) {
    World = world;
    float incr = (PI * 2.f) / AGENT_COUNT;
    for( int i = 0; i < AGENT_COUNT; i++ ) {
        if( World != nullptr ) {
            FRotator rotation = FRotator();

            FVector location = FVector();
            location.X = FMath::Sin(incr * i) * 150.f;
            location.Y = FMath::Cos(incr * i) * 150.f;

            AAgent * agent = World->SpawnActor<AAgent>(location, rotation);
            agent->Init(mesh, i);
            Agents.Add(agent);
        }
    }

    initialized = true;
}

/*
 * Safely deletes all boids agents marked for removal before updating positions
 */
void UFlockingManager::CleanUp() {
    int i = Agents.Num()-1;
    while (i >= 0)
    {
        if (Agents[i]->ToDelete)
        {
            Agents.RemoveAt(i);
        }
        i -= 1;
    }
}

/*
 * Update the positions and trajectories of the boids agents
 */
void UFlockingManager::Flock() {
    int boidCount = Agents.Num();
    for (int i = 0; i < boidCount; i++)
    {
        // Get Agent
        AAgent* currentAgent = Agents[i];
        FVector currentPos = currentAgent->GetActorLocation();
        FVector centerPos = FVector(0.f);
        FVector velocityChange = FVector(0.f);

        // Get neighbor information
        for (int j = 0; j < boidCount; j++)
        {
            // skip current boid agent
            if (i != j)
            {
                AAgent* neighborAgent = Agents[j];
                // contribute to center calculation
                centerPos += neighborAgent->GetActorLocation();

            }
        }
        
        // Evaluate rules
        // - Rule 1: Fly towards center
        centerPos /= boidCount - 1;
        velocityChange += (centerPos - currentPos) * RULE1_WEIGHT;

        // - Rule 2: 
        

        // - Rule 3: 


        // Apply results
        currentAgent->Advance(velocityChange);
    }
}