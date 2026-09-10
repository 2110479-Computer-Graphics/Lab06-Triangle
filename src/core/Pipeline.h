#ifndef __PIPELINE_H_INCLUDED__
#define __PIPELINE_H_INCLUDED__

#include "core/Buffer.h"
#include "core/Target.h"

struct Descriptors {
  VkDescriptorSetLayout layout = VK_NULL_HANDLE;
  VkDescriptorPool      pool   = VK_NULL_HANDLE;
  VkDescriptorSet       set    = VK_NULL_HANDLE;
};

VkRenderPass createRenderPass(const Device& dev);
void         destroyRenderPass(const Device& dev, VkRenderPass renderPass);

Descriptors createDescriptors(const Device& dev, const Buffer& uniform);
void        destroyDescriptors(const Device& dev, Descriptors& descs);

VkPipelineLayout createPipelineLayout(const Device& dev, const Descriptors& descs);
VkShaderModule   createShaderModule(const Device& dev, const std::string& name);

VkPipeline createPipeline(const Device& dev,
                          VkRenderPass renderPass,
                          VkPipelineLayout layout,
                          VkShaderModule vertShader,
                          VkShaderModule fragShader,
                          const Target& target);

#endif
