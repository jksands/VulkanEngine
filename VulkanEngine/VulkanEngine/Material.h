#pragma once
#include "pch.h"

class Material
{
protected:

	std::string vertexShaderPath;
	std::string fragmentShaderPath;

	VkPipelineLayout pipelineLayout;
	VkPipeline pipeline;
	
	VkDescriptorPool descriptorPool;
	VkDescriptorSetLayout descriptorSetLayout;
	std::vector<VkDescriptorSet> descriptorSets;
	std::string matPath;

public:

#pragma region Memory Management

	Material(std::string vertexShaderPath, std::string fragmentShaderPath, std::string materialPath);

	/// <summary>
	/// Creates and allocates Material resources
	/// </summary>
	void Init();

	/// <summary>
	/// Creates and allocates the graphics pipeline used by this material
	/// </summary>
	void CreateGraphicsPipeline();

	/// <summary>
	/// Creates and allocates the descriptor set layout used by this material
	/// </summary>
	void CreateDescriptorSetLayout();

	/// <summary>
	/// Creates and allocates the descriptor pool used by this material
	/// </summary>
	void CreateDescriptorPool();

	/// <summary>
	/// Creates and allocates the descriptor sets used by this material
	/// </summary>
	void CreateDescriptorSets();

	/// <summary>
	/// Cleans up the resources used by this material
	/// </summary>
	void Cleanup();

#pragma endregion

#pragma region Accessor

	/// <summary>
	/// Returns the pipeline layout associated with the material
	/// </summary>
	/// <returns>The material's pipeline layout</returns>
	VkPipelineLayout GetPipelineLayout();
	
	/// <summary>
	/// Returns the graphics pipeline associated with the material
	/// </summary>
	/// <returns>The material's graphics pipeline</returns>
	VkPipeline GetPipeline();

	/// <summary>
	/// Returns the descriptor sets used by the material
	/// </summary>
	/// <returns>The list of the material's descriptor sets</returns>
	std::vector<VkDescriptorSet> GetDescriptorSets();

#pragma endregion

#pragma region Helper Methods

	/// <summary>
	/// Creates a VkShaderModule from input shader code
	/// </summary>
	/// <param name="code">The contents of a SPIR-V </param>
	/// <returns>The VkShaderModule created from the code</returns>
	static VkShaderModule CreateShaderModule(const std::vector<char>& code);

#pragma endregion
};