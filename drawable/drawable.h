#ifndef NBOUL_OSCDISPLAY_DRAWABLE_DRAWABLE_H
#define NBOUL_OSCDISPLAY_DRAWABLE_DRAWABLE_H

#include "drawableprimitive/primitive.h"

#include <vector>

namespace nboul {
namespace oscdisplay {
namespace drawable {

class Drawable
{
public:
	virtual ~Drawable()
	{
		deletePrimitives();
	}

	void deletePrimitives()
	{
		for (auto * primitive : primitives)
			delete primitive;

		primitives.clear();
	}

	virtual void updatePrimitives()
	{
	}

	std::vector<drawableprimitive::Primitive*> primitives;
};

}  // namespace drawable
}  // namespace oscdisplay
}  // namespace nboul

#endif  // NBOUL_OSCDISPLAY_DRAWABLE_DRAWABLE_H
