
define pscene
    set $s = (t_data *)$arg0
    printf "\n========== t_data ==========\n"
    printf "\n--- ambient ---\n"
    p $s->ambient
    printf "\n--- camera ---\n"
    p $s->camera
    printf "\n--- lights ---\n"
    p $s->lights
    printf "\n--- dimensions ---\n"
    p $s->width
    p $s->height
    printf "\n--- objs ---\n"
    set $objs = (void **)$s->objs
    set $i = 0
    while $objs[$i] != 0
        printf "\nObject [%d]: ", $i
        set $type = ((t_plane *)$objs[$i])->type
        if $type == OBJ_SPHERE
            p *(t_sphere *)$objs[$i]
        else
            if $type == OBJ_CYLINDER
                p *(t_cylinder *)$objs[$i]
            else
                if $type == OBJ_PLANE
                    p *(t_plane *)$objs[$i]
                else
                    printf "Unknown type: %d\n", $type
                end
            end
        end
        set $i = $i + 1
    end
    printf "\n========== end t_data ==========\n"
end

