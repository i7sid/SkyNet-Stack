//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package skynet;

import skynet.base.connectionManager.ConnectionManager;
import skynet.base.modules.BaseWorldUtility;
import skynet.simulation.SimulationManager;
import skynet.environment.Air;
import skynet.glider.Glider;

network SkyNet
{
    parameters:
        double playgroundSizeX @unit(m);
        double playgroundSizeY @unit(m);
        double playgroundSizeZ @unit(m);

        int numNodes; // total number of hosts in the network

        @display("bgb=$playgroundSizeX,$playgroundSizeY,white;bgp=563,411");

    submodules:
        connectionManager: ConnectionManager {
            parameters:
                @display("p=79,46;i=abstract/multicast;is=s");
        }
        
        sim: SimulationManager
        {
            
        }
        
        world: BaseWorldUtility {
            parameters:
                playgroundSizeX = playgroundSizeX;
                playgroundSizeY = playgroundSizeY;
                playgroundSizeZ = playgroundSizeZ;
                @display("p=207,46");
        }
        
        air: Air {
			parameters:
            	@display("p=79,143");
        }
        
        node[numNodes]: Glider {
            parameters:
                @display("p=219,143");
        }

    connections allowunconnected:
    // all connections and gates are to be generated dynamically
}
