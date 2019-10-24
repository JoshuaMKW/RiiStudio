#pragma once

#include "Enum/CullMode.hpp"
#include "Struct/ZMode.hpp"
#include "Struct/TexGen.hpp"
#include "Struct/Shader.hpp"
#include "Enum/Comparison.hpp"

namespace libcube { namespace gx {

enum class ColorSource
{
	Register,
	Vertex
};
enum class LightID
{
	None = 0,
	Light0 = 0x001,
	Light1 = 0x002,
	Light2 = 0x004,
	Light3 = 0x008,
	Light4 = 0x010,
	Light5 = 0x020,
	Light6 = 0x040,
	Light7 = 0x080
};
enum DiffuseFunction
{
	None,
	Sign,
	Clamp
};

enum class AttenuationFunction
{
	Specular,
	Spotlight,
	None
};

struct ChannelControl
{
	bool enabled;
	ColorSource Ambient, Material;
	LightID lightMask;
	DiffuseFunction diffuseFn;
	AttenuationFunction attenuationFn;

	bool operator==(const ChannelControl& other) const
	{
		return
			enabled == other.enabled &&
			Ambient == other.Ambient &&
			Material == other.Material &&
			lightMask == other.lightMask &&
			diffuseFn == other.diffuseFn &&
			attenuationFn == other.attenuationFn;
	}
};

enum class AlphaOp
{
	and,
	or,
	xor,
	xnor
};

struct AlphaComparison
{
	Comparison compLeft;
	u8 refLeft;

	AlphaOp op;

	Comparison compRight;
	u8 refRight;
};

enum class BlendModeType
{
	none,
	blend,
	logic,
	subtract
};
enum class BlendModeFactor
{
	zero,
	one,
	src_c,
	inv_src_c,
	src_a,
	inv_src_a,
	dst_a,
	inv_dst_a
};
enum class LogicOp
{
	clear,
	and,
	rev_and,
	copy,
	inv_and,
	no_op,
	xor,
	or,
	nor,
	equiv,
	inv,
	revor,
	inv_copy,
	inv_or,
	nand,
	set
};
// CMODE0
struct BlendMode
{
	BlendModeType type;
	BlendModeFactor source, dest;
	LogicOp logic;
};
struct Color
{
	u32 r, g, b, a;
};
struct ColorS10
{
	s32 r, g, b, a;
};
} } // namespace libcube::gx