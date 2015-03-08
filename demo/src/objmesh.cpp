#include "objmesh.h"

namespace gfxengine
{
	// Clear this mesh
	void ObjMesh::clear()
	{
		vertices.clear();
		uv.clear();
		normals.clear();
		faceIndices.clear();
		vertFormat = VertexFormat::VF_NONE;
		polyRenderFormat = PolyRenderFormat::PR_NONE;
	}
}