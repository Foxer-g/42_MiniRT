define pscene
    set language c
    set $td = (t_data *)$arg0
    set $i = 0
    set print pretty on
    set print elements 0

    printf "\n===== t_data at %p =====\n", $td

    printf "\nambient:\n"
    p $td->ambient

    printf "\ncamera:\n"
    p $td->camera

    printf "\nlights:\n"
    p $td->lights

    printf "\nheight:\n"
    p $td->height

    printf "\nwidth:\n"
    p $td->width

    printf "\n===== objects =====\n"
    while (((t_plane *)$td->objs)[$i].type != 0)
        printf "\nobject[%d], type = %u\n", $i, ((t_plane *)$td->objs)[$i].type
        if (((t_plane *)$td->objs)[$i].type == OBJ_SPHERE)
            p ((t_sphere *)$td->objs)[$i]
        else
            if (((t_plane *)$td->objs)[$i].type == OBJ_PLANE)
                p ((t_plane *)$td->objs)[$i]
            else
                if (((t_plane *)$td->objs)[$i].type == OBJ_CYLINDER)
                    p ((t_cylinder *)$td->objs)[$i]
                else
                    printf "Unknown object type: %u\n", ((t_plane *)$td->objs)[$i].type
                end
            end
        end
        set $i = $i + 1
    end

    printf "\nTotal objects: %d\n", $i
    printf "\n===== end t_data =====\n"
end

document pscene
Print selected t_data fields and every object in t_data->objs.

Usage:
  pscene <t_data-pointer>
  pscene &<t_data-object>

Object dispatch uses OBJ_SPHERE, OBJ_PLANE, and OBJ_CYLINDER.
The object list must end with a type value of 0.
end
