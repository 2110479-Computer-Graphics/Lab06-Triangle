#include "utils/Vertex.h"

#include <cstring>

const std::vector<Vertex> TRIANGLE = {
  // TODO(TASK 1a): three vertices. Check values are in Part I of the handout.
};

VkVertexInputBindingDescription Vertex::bindingDescription() {
  VkVertexInputBindingDescription desc{};
  desc.binding   = 0;
  desc.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
  desc.stride    = 0;  // TODO(TASK 1b): how many bytes from one vertex to the next?
  return desc;
}

std::vector<VkVertexInputAttributeDescription> Vertex::attributeDescriptions() {
  // TODO(TASK 1c): two attributes. Each needs binding, location, format and offset.
  return {};
}

struct Params {
  std::uint32_t placeholder[20];  // TODO(TASK 2a): replace with three std140 members, padded
};

static_assert(sizeof(Params) == 80, "Params must match the std140 table in the handout");

std::vector<std::uint8_t> uniformBlock(std::uint32_t costLoops, std::uint32_t stripeWidth) {
  Params params{};
  // TODO(TASK 2b): an identity matrix, and the two knobs passed through.

  std::vector<std::uint8_t> bytes(sizeof(Params));
  std::memcpy(bytes.data(), &params, sizeof(Params));
  return bytes;
}
